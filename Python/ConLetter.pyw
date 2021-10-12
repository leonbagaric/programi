from tkinter import *

lat = ['A','B','C','Č','Ć','D','Đ','E','F','G','H','I','J','K','L','M','N','O','P','R','S','Š','T','U','V','Z','Ž','a','b','c','č','ć','d','đ','e','f','g','h','i','j','k','l','m','n','o','p','r','s','š','t','u','v','z','ž']
cir = ['А','Б','Ц','Ч','Ћ','Д','Ђ','Е','Ф','Г','Х','И','Ј','К','Л','М','Н','О','П','Р','С','Ш','Т','У','В','З','Ж','а','б','ц','ч','ћ','д','ђ','е','ф','г','х','и','ј','к','л','м','н','о','п','р','с','ш','т','у','в','з','ж']
rucir = ['А','Б','Ц','Ч','Ć','Д','Đ','Е','Ф','Г','Х','И','Й','К','Л','М','Н','О','П','Р','С','Ш','Т','У','В','З','Ж','а','б','ц','ч','ć','д','đ','е','ф','г','х','и','й','к','л','м','н','о','п','р','с','ш','т','у','в','з','ж']

def latin():
    string=""
    text=output.get("0.0",END)
    for i in text:
        flag = False
        for j in range(0, len(lat)):
            if i == rucir[j]:
                i = lat[j]
                string = string + i
                flag = True
                
            elif i == cir[j]:
                i = lat[j]
                string = string + i
                flag = True

            elif i == lat[j]:
                i = lat[j]
                string = string + i
                flag = True
        if flag == False:
            string = string + i
    output2.delete(0.0,END)
    output2.insert(END,string)
        
def serb():
    string=""
    text=output.get("0.0",END)
    for i in text:
        flag = False
        for j in range(0, len(lat)):
            if i == lat[j]:
                i = cir[j]
                string = string + i
                flag = True
                
            elif i == rucir[j]:
                i = cir[j]
                string = string + i
                flag = True

            elif i == cir[j]:
                i = cir[j]
                string = string + i
                flag = True
        if flag == False:
            string = string + i
    output2.delete(0.0,END)
    output2.insert(END,string)

def rus():
    string=""
    text=output.get("0.0",END)
    for i in text:
        flag = False
        for j in range(0, len(lat)):
            if i == lat[j]:
                i = rucir[j]
                string = string + i
                flag = True
                
            elif i == cir[j]:
                i = rucir[j]
                string = string + i
                flag = True

            elif i == rucir[j]:
                i = rucir[j]
                string = string + i
                flag = True
        if flag == False:
            string = string + i
    output2.delete(0.0,END)
    output2.insert(END,string)

window = Tk()
window.title("ConLetter")
window.configure(background="black")

Label (window, text='Your text:', bg="black", fg="white", font="none 12 bold") .grid(row=0, column=0, sticky=W)
Label (window, text='Converted:', bg="black", fg="white", font="none 12 bold") .grid(row=0, column=2, sticky=W)

output = Text(window, width=40,height=6, wrap=WORD, background="white")
output.grid(row=1, column=0, columnspan=2,sticky=W)

output2 = Text(window, width=40,height=6, wrap=WORD, background="white")
output2.grid(row=1, column=2, columnspan=2,sticky=W)

Button(window, text="Latin", width=15, command=latin) .grid(row=2, column=0,sticky=W)
Button(window, text="Serbian cyrilic", width=15, command=serb) .grid(row=2, column=1,sticky=W)
Button(window, text="Russian cyrilic", width=15, command=rus) .grid(row=2, column=2,sticky=W)

Label (window, text='', bg="black", fg="black", font="none 12 bold") .grid(row=3, column=0, sticky=W)

window.iconbitmap(default='logo.ico')
window.resizable(0,0)
window.mainloop()

while True:
    l = input()
    print("")
    for i in l:
        flag = False
        for j in range(0, len(lat)):
            if i == lat[j]:
                i = cir[j]
                print(i, end = '')
                flag = True
                
            elif i == cir[j]:
                i = lat[j]
                print(i, end = '')
                flag = True
        if flag == False:
            print(i, end = '')

            
    print("")
    print("")

