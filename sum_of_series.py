def series_sum(n):
    result = 1
    temp = 1
    # If the given value is 0 then it should return 0.00 as String
    if n == 0:
        return '0.00'
    # If the given value is 1 then it should return 1.00 as String
    if n == 1:
        return '1.00'
    # Calculate answer
    for i in range(n-1):
        result += 1 / (temp+3)
        temp += 3
    # If there is one number after comma then we add 0
    if len(str(round(result, 2))) == 3:
        return f"{str(round(result, 2))}0"
    # else we return our rounded answer with 2 numbrers after comma
    return str(round(result, 2))
