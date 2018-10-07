# -*- coding: utf-8 -*-
import pathlib
from ctypes import *

testdll = windll.LoadLibrary(str(pathlib.Path(__file__).resolve().parent) + "\\dlltest.dll")

cnt = testdll.TestCount(1)
print(cnt)
cnt = testdll.TestCount(2)
print(cnt)
print("---")

p1 = create_string_buffer(b"ABCdefgHIJk123")
print("TestLower(" + str(p1.value) + ")")
testdll.TestLower.restype = c_char_p
p2 = testdll.TestLower(p1, len(p1))
print("p1=" + str(p1.value))
print("p2=" + str(p2))
print("---")

pw1 = create_unicode_buffer("ABC123cdfgあいうｴｵ")
testdll.TestFullWidth.restype = c_wchar_p
print("TestFullWidth(" + str(pw1.value) + ")")
pw2 = testdll.TestFullWidth(pw1, len(pw1))
print("p1=" + str(pw1.value))
print("p2=" + str(pw2))
