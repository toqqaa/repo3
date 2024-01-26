import cv2
import numpy as np

def get_outputs_names(net):
    layers_names = net.getLayerNames()
    output_layer_indices = [layers_names[i[0] - 1] for i in net.getUnconnectedOutLayers()]

    output_layer_names = [layers_names[idx - 1] for idx in output_layer_indices]

    return output_layer_names

def postprocess(frame, outputs, fps):
    frame_height, frame_width = frame.shape[:2]

    for detection in outputs[0, 0]:
        class_id = int(detection[1])
        confidence = detection[2]
        
        if confidence > 0.5 and class_id == 15:
            box = detection[3:7] * np.array([frame_width, frame_height, frame_width, frame_height])
            (startX, startY, endX, endY) = box.astype("int")
            cv2.rectangle(frame, (startX, startY), (endX, endY), (0, 255, 0), 2)

            confidence_percentage = int(confidence * 100)
            text = f"FPS: {fps:.2f}, Accuracy: {confidence_percentage}%"
            cv2.putText(frame, text, (startX, startY - 20), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)

ssd_net = cv2.dnn.readNetFromCaffe("/home/toqa/MobileNet-SSD/deploy.prototxt", "/home/toqa/MobileNet-SSD/mobilenet_iter_73000.caffemodel")
if ssd_net.empty():
    print("Error loading SSD MobileNet model.")
    exit()

cap = cv2.VideoCapture("/home/toqa/Downloads/people.mp4")

if not cap.isOpened():
    print("Error opening video file.")
    exit()

start_time = cv2.getTickCount()
frame_count = 0
fps_interval = 5  

try:
    while True:
        ret, frame = cap.read()
        if not ret:
            break

        blob = cv2.dnn.blobFromImage(frame, 0.007843, (300, 300), 127.5)
        ssd_net.setInput(blob)
        ssd_outputs = ssd_net.forward()

        end_time = cv2.getTickCount()
        elapsed_time = (end_time - start_time) / cv2.getTickFrequency()
        fps = frame_count / elapsed_time
        print(f"FPS for frame {frame_count}: {fps:.2f}")

        postprocess(frame, ssd_outputs, fps)

        cv2.imshow("People Detection (SSD MobileNet)", frame)

        frame_count += 1
        if frame_count % (fps_interval * cap.get(cv2.CAP_PROP_FPS)) == 0:
            start_time = cv2.getTickCount()

        if cv2.waitKey(1) == ord('q'):
            break

except KeyboardInterrupt:
    pass  

cap.release()
cv2.destroyAllWindows()
