
import cv2
import numpy as np
from matplotlib import pyplot as plt
# Read the image
img = cv2.imread('shapes.png')
# Convert the image to grayscale
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
# Apply a binary threshold to create a binary image
_, threshold = cv2.threshold(gray, 127, 255, cv2.THRESH_BINARY)
# Find contours in the binary image
contours, _ = cv2.findContours(threshold, cv2.RETR_TREE,
cv2.CHAIN_APPROX_SIMPLE)
# Counter to skip the first contour (whole image)
i = 0
# List for storing names of shapes
for contour in contours:
# Ignore the first contour because findContours detects the whole
  if i == 0:
    i = 1
    continue
# Approximate the shape using cv2.approxPolyDP() function
  epsilon = 0.01 * cv2.arcLength(contour, True)
  approx = cv2.approxPolyDP(contour, epsilon, True)
# Draw contours on the original image
  cv2.drawContours(img, [contour], 0, (0, 0, 255), 2)
# Finding the center point of the shape
  M = cv2.moments(contour)
if M['m00'] != 0.0:
   x = int(M['m10'] / M['m00'])
   y = int(M['m01'] / M['m00'])
# Display the center points on the image
   cv2.circle(img, (x, y), 2, (255, 0, 0), -1)
# Display the original image with contours and center points
cv2.imshow("Shapes with Contours and Center Points", img)
cv2.waitKey(0)
cv2.destroyAllWindows()