# 4949
s = input()
while (s != '.'):
    arr = list(s)
    stack = [0]
    for i in arr:
        flag = 0
        if (i == ')'):
            if (stack.pop() != '('):
                print("no")
                flag = 1
                break

            else:
                pass

        elif (i == ']'):
            if (stack.pop() != '['):
                print("no")
                flag = 1
                break

            else:
                pass

        elif (i == '(' or i == '['):
            stack.append(i)

        else:
            pass

    if (flag == 1):
        s = input()
        continue

    if (0 in stack):
        stack.remove(0)

    if (len(stack) == 0):
        print("yes")

    else:
        print("no")

    s = input()