#---- TASK: Use PIL and matplotlib to read and display the 00-puppy.jpg image.

import cv2 as cv
import numpy as np
from PIL import Image
import matplotlib.pyplot as plt

path = r"00-puppy.jpg"
image = Image.open(path)
image_plt = np.array(image)
image_plt = cv.resize(image_plt,(512,512))

plt.imshow(image_plt)
plt.axis('off')  
plt.title("Puppy Image")
plt.show()
#TASK: Use slicing to set the RED and GREEN channels of the picture to 0, then use imshow() to show the isolated blue channel.
copy_image = image_plt
copy_image[:, :, 1] = 0 #g=0
copy_image[:, :, 2] = 0 #r=0
cv.imshow("Blue", copy_image)
cv.waitKey(0)