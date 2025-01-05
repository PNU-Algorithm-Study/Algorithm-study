x,y=map(int,input().split())
op =['+','-','*','//','%']
for i in op:
    exec(f"print({x} {i} {y})")