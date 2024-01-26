import cv2
import numpy as np

def calculate_accuracy(true_labels, predicted_labels):
    correct_predictions = sum(1 for true, pred in zip(true_labels, predicted_labels) if true == pred)
    total_predictions = len(true_labels)

    accuracy = correct_predictions / total_predictions if total_predictions > 0 else 0
    return accuracy

def get_outputs_names(net):
    layers_names = net.getLayerNames()
    output_layer_indices = net.getUnconnectedOutLayers()
    output_layer_names = [layers_names[idx - 1] for idx in output_layer_indices]

    return output_layer_names

def postprocess(frame, outputs, fps, true_labels):
    frame_height, frame_width = frame.shape[:2]
    predicted_labels = []

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

                # Replace this line with the actual ground truth labels for each frame
                true_label = np.random.choice([0, 1])
                predicted_labels.append(class_id)

    # Calculate accuracy
    accuracy = calculate_accuracy(true_labels, predicted_labels)
    accuracy_text = f"Accuracy: {accuracy * 100:.2f}%"
    cv2.putText(frame, accuracy_text, (10, 90), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)

    # Display FPS and average FPS at the top left corner of the video
    average_fps = fps_accumulator / frame_count if frame_count > 0 else 0
    fps_text = f"Current FPS: {fps:.2f}, Average FPS: {average_fps:.2f}"
    cv2.putText(frame, fps_text, (10, 60), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)


yolo_net = cv2.dnn.readNet("/home/toqa/darknet/yolov3-tiny.weights", "/home/toqa/darknet/cfg/yolov3-tiny.cfg")
if yolo_net.empty():
    print("Error loading Tiny YOLO model.")
    exit()

cap = cv2.VideoCapture("/home/toqa/Downloads/people.mp4")

if not cap.isOpened():
    print("Error opening video file.")
    exit()

start_time = cv2.getTickCount()
frame_count = 0
fps_interval = 5 
fps_accumulator = 0
true_labels = np.random.choice([0, 1], size=100)  # Replace with actual ground truth labels

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
        fps_accumulator += fps

        postprocess(frame, yolo_outputs, fps, true_labels)

        # Display FPS at the left top corner of the video
        average_fps = fps_accumulator / frame_count if frame_count > 0 else 0
        fps_text = f"Current FPS: {fps:.2f}, Average FPS: {average_fps:.2f}"
        cv2.putText(frame, fps_text, (10, 60), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)

        cv2.imshow("People Detection (Tiny YOLO)", frame)
        frame_count += 1

        if elapsed_time >= fps_interval:
            frame_count = 0
            fps_accumulator = 0
            start_time = cv2.getTickCount()

        if cv2.waitKey(1) == ord('q'):
            break

except KeyboardInterrupt:
    pass  

cap.release()
cv2.destroyAllWindows()
