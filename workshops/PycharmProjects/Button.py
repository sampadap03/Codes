# button to execute a command
import tkinter as tk


def write_slogan():
    print("Hello sudeshna!")


def message():
    print("SUUD!!! What are you doing?")

def reply():
    print("HAve a nice day")
root = tk.Tk()
frame = tk.Frame(root)
frame.pack()

button = tk.Button(frame, text="QUIT", fg="red", command=quit)
button.pack(side=tk.LEFT)

slogan = tk.Button(frame, text="Hello", command=write_slogan)
slogan.pack(side=tk.LEFT)

sudeshna = tk.Button(frame, text="Message",fg="blue",command=message)
sudeshna.pack(side=tk.RIGHT)

sampada=tk.Button(frame,text="REPLY",fg="green",command=reply)
sampada.pack(side=tk.RIGHT)
root.mainloop()