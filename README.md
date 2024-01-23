# P-EXE
Tiny executable stub able to run .ps1 Powershell scripts on click.

## The issue
Powershell is the _new_ thing for Windows. We can do some things that would take more effort to do with classic batch scripts and good old _Command Prompt_.

However, running Powershell scripts poses a hassle as in, in the name of security, we cannot simply run them like we run regulat .bat files.

Good on Microsoft to focus on this aspect of security while leaving everything else to just run amok though 👏🏾.

Anyway, I've added a tiny program to simply run these .ps1 scripts.

You can download it from the [releases](https://github.com/twosixfoursix/P-EXE/releases) page, or compile it from [source](https://github.com/twosixfoursix/P-EXE/blob/main/pexe/pexe.cxx).

By default, the program will run the content of a file named ```app.x``` (_if present_) as a Powershell script. Or we can pass a script file as the program argument.
```
pexe myScript.x
```

> The reason we might not want to use .bat scripts instead of all this in the first place is because for more complicated scripts, it's more convenient to use the PS scripting language. BAT scripting syntax is rather archaic and convoluted while the newer PS syntax is more like the classic ones we're used to. Once a script gets to loops and multiple branches, I find it much easier to just use PS. A BAT script might even throw errors for things like space between operators so it becomes rather exhausting real fast.
