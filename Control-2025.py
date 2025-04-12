import serial
import time
import pygame 

ser = serial.Serial(port ='COM12', baudrate=115200, timeout=0.000000000000000000001)

pygame.init()
pygame.joystick.init()
joystick = pygame.joystick.Joystick(0)
joystick.init()

Front = Back = Right = Left = Up = Down = Rotate_v_R = Rotate_v_L = Rotate_h_L = Rotate_h_R = Griber1 = Griber2 = '0'

while True :
    pygame.event.pump() 
    pygame.event.get()

    #__________________________________________________ROW___________________________________________________
    Front_Back = round(joystick.get_axis(1),2)
    Right_Left = round(joystick.get_axis(0),2)
    FB = Front_Back
    RL = Right_Left
    if Front_Back < 0 : FB *= (-1)
    if Right_Left < 0 : RL *= (-1)
    if FB > RL :
        N = int(FB * 8)
        if Front_Back < 0 : Front = str(N)
        else : Front = '0'
        if Front_Back > 0 : Back = str(N)
        else : Back = '0'

    else :
        N2 = int(RL * 8)
        if Right_Left < 0 : Left = str(N2)
        else : Left = '0'
        if Right_Left > 0 : Right = str(N2)
        else : Right = '0'
    # Rotate Horizontal
    Rotate_H_Right = round(joystick.get_axis(5),2)
    Rotate_H_Left = round(joystick.get_axis(4),2)
    N3 = int((Rotate_H_Right*4)+4)
    if N3 : Rotate_h_R = str(N3)
    else : Rotate_h_R = '0'
    N4 = int((Rotate_H_Left*4)+4)
    if N4 : Rotate_h_L = str(N4)
    else : Rotate_h_L = '0'

    #_________________________________________________Column_________________________________________________
    Up_Down = round(joystick.get_axis(3),2)
    Rotate_UpDown = round(joystick.get_axis(2),2)
    UD = Up_Down
    RUD = Rotate_UpDown
    if Up_Down < 0 : UD *= (-1)
    if Rotate_UpDown < 0 : RUD *= (-1)
    if UD > RUD :
        N5 = int(UD * 8)
        if Up_Down < 0 : Up = str(N5)
        else : Up = '0'
        if Up_Down > 0 : Down = str(N5)
        else : Down = '0'
    else :
        N6 = int(RUD * 8)
        if Rotate_UpDown < 0 : Rotate_v_L = str(N6)
        else : Rotate_v_L = '0'
        if Rotate_UpDown > 0 : Rotate_v_R = str(N6)
        else : Rotate_v_R = '0'

    #_________________________________________________Griber_________________________________________________
    Griber1 = str(joystick.get_button(10))
    Griber2 = str(joystick.get_button(9))

    #__________________________________________________Send__________________________________________________
    SEND = Front + Back + Right + Left + Up + Down + Rotate_h_R + Rotate_h_L + Griber1 + Griber2

    #time.sleep(0.05)
    ser.write(SEND.encode())
    print(SEND)


    