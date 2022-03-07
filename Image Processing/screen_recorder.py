from PIL import ImageGrab
import numpy as np
import cv2
import ctypes
import datetime

out_file = datetime.datetime.now().strftime('%Y-%m-%d %H-%M-%S')

screen_x = ctypes.windll.user32.GetSystemMetrics(78)
screen_y = ctypes.windll.user32.GetSystemMetrics(79)

fourcc = cv2.VideoWriter_fourcc('m', 'p', '4', 'v')
captured_video = cv2.VideoWriter(out_file + '.mp4', fourcc, 15.0, (screen_x, screen_y))

while True:
  img = ImageGrab.grab(bbox=(0, 0, screen_x, screen_y))
  img_np = np.array(img)
  img_final = cv2.cvtColor(img_np, cv2.COLOR_BGR2RGB)
  cv2.imshow('Capturing', img_final)
  captured_video.write(img_final)
  if cv2.waitKey(10) == ord('q'):
    break
