# When someone's hands appear in the camera's field of view, then "anchor points" and lines that connect them appear on them.

import cv2
import mediapipe as mp

# Change this parametr if you want to have more hands in camera's field of view.
max_hands = 2

cameraCapture = cv2.VideoCapture(0)

mpHands = mp.solutions.hands
hands = mpHands.Hands(False, max_hands)
mpDraw = mp.solutions.drawing_utils

while True:
    success, img = cameraCapture.read()
    imgRGB = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
    exitImage = hands.process(imgRGB)
    #print(exitImage.multi_hand_landmarks)

    if exitImage.multi_hand_landmarks:
        for handLms in exitImage.multi_hand_landmarks:
            mpDraw.draw_landmarks(img, handLms, mpHands.HAND_CONNECTIONS)

    cv2.imshow("WebCam", img)
    cv2.waitKey(1)
