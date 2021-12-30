def to_underscore(string):
    if type(string) is int:
        return str(string)
    
    new_string = ""
    
    for char in string:
        if char.isupper():
            new_string += '_' + char.lower()
        else:
            new_string += char
    
    return new_string.replace('_', '', 1)
