try:
    f2 = open("test.txt", "r")
except FileNotFoundError:
    print("File is not found")
except:
    print("Sth else went wrong")

f1 = open("test2.txt", "w")
abc = f2.read()
abc = list(abc)
for i in range(len(abc)):
    if abc[i] == '\n':
        f1.write(' ')
    else:
        f1.write(abc[i])
