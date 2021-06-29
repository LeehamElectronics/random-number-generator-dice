'VET IT Dice project (picaxe attempt)
'Coded by Liam Price from BSSC
	' output0 = diagonal /
	' output1 = centre dot
	' output2 = centre -
	' output3 = diagonal \
	' 3   0
	' 2 1 2
	' 0   3
' Shows output on varying values on LEDs
' to give impression LEDs are rolling
' when switch is pressed jump down to display
main:
if pinc.3 = 1 then display
random b0
symbol pins = b0
low B.0 low B.1 low B.2 low B.3
goto main

' check random value and split into
' six equal parts to get digits
' 1 to 6 from possible values 0 to 255
display:
if b0 > 215 then show6
if b0 > 172 then show5
if b0 > 129 then show4
if b0 > 86 then show3
if b0 > 43 then show2
goto show1
show6:     high B.0 high B.2 high B.3 
pause 2000
goto main
show5:     high B.0 high B.3 high B.1
pause 2000
goto main
show4:     high B.0 high B.3
pause 2000
goto main
show3:     high B.1 high B.3
pause 2000
goto main
show2:     high B.3
pause 2000
goto main
show1:     high B.1 
pause 2000
goto main