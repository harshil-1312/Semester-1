import pyautogui as gui
import time

#pause 5 seconds while you set focus to the terminal/console window:
print('Click on the terminal/console window where the automated keyboard data needs to be entered...')
print('Note : You have 5 second to do this!')
time.sleep(5)

#auto tyep test data from test file:
with open('w5p2-inputs.txt', 'r') as tst:
    time.sleep(1)
    tst = tst.readlines()
    for i in range(0, len(tst), 1):
        print(tst[i])
        gui.typewrite(tst[i])

print('Auto data input completed.')