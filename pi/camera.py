# live_window_usb.py
import cv2

cap = cv2.VideoCapture(0)  # try 1 if you have multiple cameras
cap.set(cv2.CAP_PROP_FRAME_WIDTH, 1280)
cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 720)

if not cap.isOpened():
    raise RuntimeError("Could not open /dev/video0")

print("Press 'q' to quit.")
while True:
    ok, frame = cap.read()
    if not ok:
        break
    cv2.imshow("USB Arducam Live", frame)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()

