def not_ordinary(numbers):
    #your code here
    first = []
    second = []
    nums = numbers.split()
    for integer in nums:
        if integer != ' ':
            if int(integer) % 2 > 0:
                first.append(nums.index(integer) + 1)
            else:
                second.append(nums.index(integer) + 1)
        else:
            pass
    if len(first) == 1:
        return int(first[0])
    else:
        return int(second[0])
