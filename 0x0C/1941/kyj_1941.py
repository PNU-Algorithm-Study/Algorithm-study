dr = [-1, 1, 0, 0]
dc = [0, 0, -1, 1]

def func(route, Y_member):
    global result

    if Y_member >= 4:
        return

    tuple_route = tuple(sorted(route))
    if tuple_route in route_check:
        return
    else:
        route_check.add(tuple_route)

    if len(route) == 7:
        result += 1
        return

    for r, c in route:
        for i in range(4):
            nr = r + dr[i]
            nc = c + dc[i]

            if not (0 <= nr < 5 and 0 <= nc < 5) or ((nr, nc) in route):
                continue

            if IN[nr][nc] == 'Y':
                func(route + [(nr, nc)], Y_member + 1)
            else:
                func(route + [(nr, nc)], Y_member)


IN = [list(input()) for _ in range(5)]
result = 0
route_check = set()

for r in range(5):
    for c in range(5):
        Y_member = 1 if IN[r][c] == 'Y' else 0
        func([(r, c)], Y_member)

print(result)