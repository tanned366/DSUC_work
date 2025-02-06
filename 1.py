import math
def gcd(a,b):
    if b==0:
        return a;
    return gcd(b, a%b)

a = int(input("Enter a no: "))
b = int(input("Enter another no: "))
c = math.gcd(a,b)
d = gcd(a,b)
print(f"GCD of {a} and {b} is: {c}")
print("GCD of {} and {} is: {}".format(a,b,d))