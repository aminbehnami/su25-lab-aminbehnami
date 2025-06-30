def fizzbuzz(num):
    if num % 3 == 0 and num % 5 == 0:
        print(f"{num}: fizzbuzz")
    elif num % 3 == 0:
        print(f"{num}: fizz")
    elif num % 5 == 0:
        print(f"{num}: buzz")

for i in range(1, 20):
    fizzbuzz(i)
