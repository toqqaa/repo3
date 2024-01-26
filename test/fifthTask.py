#TASK: Create a script that opens the picture and allows you to draw empty red circles whever you click the RIGHT MOUSE BUTTON DOWN
import cv2

def draw_circle(event, x, y, flags, param):
    global drawing

    if event == cv2.EVENT_RBUTTONDOWN:
        drawing = True
        cv2.circle(img, (x, y), 50, (0, 0, 255), 2)

    elif event == cv2.EVENT_RBUTTONUP:
        drawing = False
img = cv2.imread("dog_backpack.jpg")


cv2.namedWindow('dog')

cv2.setMouseCallback('dog', draw_circle)

drawing = False

while True:
    cv2.imshow('dog', img)
    # Exit the loop if the 'Esc' key is pressed
    if cv2.waitKey(1) == 27:
        break
cv2.destroyAllWindows()