class Solution:
    def myAtoi(self, str: str) -> int:
        
        while len(str) > 0 and str[0] == ' ':
            str = str[1:]
        if len(str) == 0:
            return 0    
        if not (str[0] == '-' or str[0] == "+" or (str[0] >= '0' and str[0] <= '9')):
            return 0
        
        if str[0] == '-':
            factor = -1
            str = str[1:]
        elif str[0] == '+':
            factor = 1
            str = str[1:]
        else:
            factor = 1
        
        final = 0
        while  len(str) > 0 and str[0] >= '0' and str[0] <= '9':
            final = final * 10 + int(str[0])
            str = str[1:]
        
        
        if final >= 2**31:
            final = 2**31 - 1
            if factor == -1:
                final += 1
        return final*factor