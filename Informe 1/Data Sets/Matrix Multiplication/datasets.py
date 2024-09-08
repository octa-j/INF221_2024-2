import random
import os

# Generate and write to files
with open("randomA.txt", "w") as file:
    random_numbers = [str(random.randint(0, 500)) for _ in range(100000)]
    file.write(" ".join(random_numbers))

with open("randomB.txt", "w") as file:
    random_numbers = [str(random.randint(0, 500)) for _ in range(100000)]
    file.write(" ".join(random_numbers))
