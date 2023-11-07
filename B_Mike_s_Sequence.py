R = int(input())
ratings = [1200,1400,1600,1900,2100,2300,2400,2600,3000]
higher = [r for r in ratings if r > R]
print(higher[0])