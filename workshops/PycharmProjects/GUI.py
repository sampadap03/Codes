'''import tkinter
top=tkinter.Tk()
top.mainloop()'''

'''import tkinter as tk
root=tk.Tk()
w=tk.Label(root,text="HEllo world")
w.pack()
root.mainloop()'''

#put chckbuttons on screen
import tkinter
master=tkinter.Tk()
var1=tkinter.IntVar()
tkinter.Checkbutton(master,text="physics",variable=var1).grid(row=0,sticky="w")
var2=tkinter.IntVar()
tkinter.Checkbutton(master,text="chemistry",variable=var2).grid(row=1,sticky="w")
var3=tkinter.IntVar()
tkinter.Checkbutton(master,text="biology",variable=var3).grid(row=3,sticky="w")
var4=tkinter.IntVar()
tkinter.Checkbutton(master,text="mathematics",variable=var4).grid(row=4,sticky="w")
master.mainloop()

#button to execute a command
import tkinter as tk

def write_slogan():
    print("Hello sudeshna!")

def message():
    print("SUUD!!! What are you doing?")

root=tk.Tk()
frame=tk.Frame(root)
frame.pack()

button= tk.Button(frame,text="QUIT",fg="red",command=quit)
button.pack(side=tk.LEFT)

slogan=tk.Button(frame,text="Hello",command=write_slogan)
slogan.pack(side=tk.LEFT)

sudeshna=tk.Button(frame,text="Message",command=message)
sudeshna.pack(side=tk.LEFT)
root.mainloop()