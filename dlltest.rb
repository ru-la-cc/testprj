require 'fiddle/import'
require 'fiddle/types'

module DllTest extend Fiddle::Importer
	dlload __dir__ + '/dlltest.dll'
	include Fiddle::BasicTypes
	include Fiddle::Win32Types
	typealias 'LPWSTR', 'wchar_t*'
	extern "int TestCount(int)"
	extern "LPSTR TestLower(LPSTR, int)"
	extern "LPWSTR TestFullWidth(LPWSTR, int)"
end

cnt = DllTest::TestCount(1)
puts "counter : " + cnt.to_s
cnt = DllTest::TestCount(2)
puts "counter : " + cnt.to_s
puts "---"

p1 = "ABCdefgHIJk123"
puts "TestLower(" + p1 + ")"
p2 = DllTest::TestLower(p1.encode!('Shift_JIS'), p1.length)
puts "p1=" + p1
puts "p2=" + p2.to_s.force_encoding('Shift_JIS').encode('UTF-8')
puts "---"


pw1 = "ABC123cdfgあいうｴｵ"
puts "TestFullWidth(" + pw1 + ")"
pw2 = DllTest::TestFullWidth(pw1.encode!('UTF-16LE'), pw1.length)
puts "pw1=" + pw1.encode('UTF-8')
puts "pw2=" + pw2.to_s.force_encoding('UTF-16LE').encode('UTF-8')

exit(0)
