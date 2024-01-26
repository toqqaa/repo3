import cv2 as cv
import matplotlib.pyplot as plt
import numpy as np
from PIL import Image
#TASK: Open the dog_backpack.png image from the DATA folder and display it. Make sure to correct for the RGB order.
dog = Image.open("dog_backpack.jpg")
dog_array =  np.array(dog)
dog_array = cv.resize(dog_array, (500, 500))
dog_array = cv.cvtColor(dog_array, cv.COLOR_RGB2BGR)
cv.imshow("The DOG", dog_array)
cv.waitKey(0)

##TASK: Flip the image upside down and display it
dog_rotate = cv.cvtColor(dog_array, cv.COLOR_RGB2BGR)
dog_rotate = cv.rotate(dog_array,cv.ROTATE_180)
cv.imshow("The DOG_Flip", dog_rotate)
cv.waitKey(0)

#TASK: Draw an empty RED rectangle around the dog face and display the image.
dog_rectangle = dog_array.copy()
start_point = (112,148)
end_point = (328,270)

cv.rectangle(dog_rectangle, start_point, end_point, (0,0,255), 3)
cv.imshow("The DOG_rectangle", dog_rectangle)
cv.waitKey(0)



#TASK: Draw a BLUE TRIANGLE in the middle of the image. The size and angle is up to you, but it
#should be a triangle (three sides) in any orientation. (use polygon)
dog_triangle = dog_array
height = dog_triangle.shape[0]
width = dog_triangle.shape[1]
center_x  = width // 2
center_y = height // 2
triangle_vertices = np.array([
    [center_x, center_y - 100],  
    [center_x - 100, center_y + 100], 
    [center_x + 100, center_y + 100]  
], dtype=np.int32)
triangle_vertices = triangle_vertices.reshape((-1, 1, 2))

cv.polylines(dog_triangle, [triangle_vertices], isClosed=True, color=(255, 0, 0), thickness=2)

cv.imshow("The DOG_triangle", dog_triangle)


cv.waitKey(0)

#fill blue triangle
dog_tringle_filled = dog_array

cv.fillPoly(dog_tringle_filled, [triangle_vertices], color=(255, 0, 0))

cv.imshow("The DOG_triangle_filled", dog_tringle_filled)


cv.waitKey(0)