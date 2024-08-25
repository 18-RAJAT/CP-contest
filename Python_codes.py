Questions={
    "What is the keyword to define a variable in Python?":"=",
    "Which symbol is used for comments in Python?":"#",
    "What function is used to print text in Python?":"print",
    "How do you start a loop in Python?":"for",
    "Which data type is used to store text?":"string"
}
your_score=sum(1 for i,j in Questions.items() if input(i+" ").lower()==j.lower())
print(f"Your score: {your_score}/{len(Questions)}")
