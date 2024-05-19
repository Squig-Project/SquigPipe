@echo off
cl .\src\main.c /FC /Zi /MDd /nologo user32.lib gdi32.lib kernel32.lib comdlg32.lib Comctl32.lib /DUNICODE /D_UNICODE