#!/usr/bin/python

def match_parentheses(s):
    list = []
    parentheses = "()[]{}"
    for i in range(len(s)):
        si = s[i]
        if parentheses.find(si) == -1:
            continue
        if si == '(' or si == '[' or si == '{':
            list.append(si)
            continue
        if len(list) == 0:
            return False
        p = list.pop()
        if (p == '(' and si == ')') or (p == '[' and si == ']') or (p == '{' and si == '}'):
            continue
        else:
            return False

    if len(list) > 0:
        return False
    return True


if __name__ == '__main__':
    s = "()"
    result = match_parentheses(s)
    print(s, result)
