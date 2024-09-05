import random
import os

# In order to partially order array
def partial():
    numbers = []
    for i in range(0, 1000001, 1000):
        # Generate a random chunk of ordered numbers
        chunk = sorted(random.randint(0, 5000000) for _ in range(min(1000, 10000001 - i)))
        # Shuffle the chunk partially (not fully)
        random.shuffle(chunk)
        numbers.extend(chunk)
    return numbers

# Generate and write to files

with open("ascending.txt", "w") as file:
    file.write(" ".join(map(str, range(1000001))))

with open("partial.txt", "w") as file:
    random_numbers = partial()
    file.write(" ".join(map(str, random_numbers)))


with open("random.txt", "w") as file:
    random_numbers = [str(random.randint(0, 5000000)) for _ in range(1000001)]
    file.write(" ".join(random_numbers))





