import random
import os

# Generate and write to files
with open("randomA.txt", "w") as file:
    random_numbers = [str(random.randint(0, 5000000)) for _ in range(1000001)]
    file.write(" ".join(random_numbers))

with open("randomB.txt", "w") as file:
    random_numbers = [str(random.randint(0, 5000000)) for _ in range(1000001)]
    file.write(" ".join(random_numbers))
