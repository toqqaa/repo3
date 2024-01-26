import cv2
import numpy as np

def get_outputs_names(net):
    layers_names = net.getLayerNames()
    output_layer_indices = net.getUnconnectedOutLayers()
    output_layer_names = [layers_names[idx - 1] for idx in output_layer_indices]

    return output_layer_names

def postprocess(frame, outputs, fps):
    frame_height, frame_width = frame.shape[:2]

    for output in outputs:
        for detection in output:
            scores = detection[5:]
            class_id = np.argmax(scores)
            confidence = scores[class_id]

            if confidence > 0.5 and class_id == 0:
                center_x = int(detection[0] * frame_width)
                center_y = int(detection[1] * frame_height)
                width = int(detection[2] * frame_width)
                height = int(detection[3] * frame_height)
                top_left_x = int(center_x - width / 2)
                top_left_y = int(center_y - height / 2)
                cv2.rectangle(frame, (top_left_x, top_left_y), (top_left_x + width, top_left_y + height), (0, 255, 0), 2)

                confidence_percentage = int(confidence * 100)
                text = f"FPS: {fps:.2f}, Accuracy: {confidence_percentage}%"
                cv2.putText(frame, text, (top_left_x, top_left_y - 20), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)

yolo_net = cv2.dnn.readNet("/home/toqa/darknet/yolov3.weights", "/home/toqa/darknet/cfg/yolov3.cfg")
if yolo_net.empty():
    print("Error loading  YOLO model.")
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

        
        blob = cv2.dnn.blobFromImage(frame, 0.00392, (416, 416), (0, 0, 0), True, False)
        yolo_net.setInput(blob)
        yolo_outputs = yolo_net.forward(get_outputs_names(yolo_net))

        
        end_time = cv2.getTickCount()
        elapsed_time = (end_time - start_time) / cv2.getTickFrequency()
        fps = frame_count / elapsed_time
        print(f"FPS for frame {frame_count}: {fps:.2f}")

        
        postprocess(frame, yolo_outputs, fps)


        cv2.imshow("People Detection (YOLO)", frame)

        
        frame_count += 1

        
        if frame_count % (fps_interval * cap.get(cv2.CAP_PROP_FPS)) == 0:
            start_time = cv2.getTickCount()

        if cv2.waitKey(1) == ord('q'):
            break

except KeyboardInterrupt:
    pass  

cap.release()
cv2.destroyAllWindows()
