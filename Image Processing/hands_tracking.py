import cv2
import mediapipe as mp

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
