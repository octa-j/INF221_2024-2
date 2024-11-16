import random
import sys

''' 
Generador de strings de prueba
Recibe nombre del archivo a generar
Crea un archivo con string aleatorio de tamaño 200 en archivo especificado
'''

filename = input("Ingrese nombre del archivo a crear: ")
amount = int(input("Ingrese cantidad de caracteres: "))

f = open(filename, 'w')
sys.stdout = f
'''
for i in range(amount):
	print (chr(random.randint(97, 122)), end="")
'''

print ('a'*amount)
