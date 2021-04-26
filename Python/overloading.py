import string


def sum(datatype, datatype2, *args):
    if datatype == 'int' and datatype2 == 'int':
        answer = 0
        for x in args:
            answer = answer + x
    
    elif datatype == 'str' and datatype2 == 'str':
        answer = ''
        for x in args:
            answer = answer + x
    
    elif datatype == 'int' and datatype2 == 'str':
        answer = ''
        for x in args:
            num_str = str(x)
            answer = answer + num_str
    
    print(answer)

sum('int', 'int', 1, 2)
sum("str", "str", "Hello", "world")
sum('int', 'str', 3, "world")
