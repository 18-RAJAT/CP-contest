import random
choices=["rock","paper","scissors"]
user=input("Select one (rock, paper, or scissors): ").lower()
computer=random.choice(choices)
win_conditions={"rock":"scissors","paper":"rock","scissors":"paper"}
if user==computer:
    result="It's a tie"
elif win_conditions[user]==computer:
    result="You win"
else:
    result="Computer wins"
print(f"Computer chose: {computer}")
print(result)
