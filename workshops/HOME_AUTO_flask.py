from flask import Flask
import RPi.GPIO as GPIO

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(16,GPIO.OUT)
GPIO.setup(20,GPIO.OUT)
GPIO.setup(21,GPIO.OUT)


app = Flask(__name__)

@app.route('/lamp1on')
def lamp1on():
    GPIO.output(16,True)
    return 'Lamp1 Switched ON'

@app.route('/lamp1off')
def lamp1off():
    GPIO.output(16,False)
    return 'Lamp1 Switched OFF'

@app.route('/lamp2on')
def lamp2on():
    GPIO.output(20,True)
    return 'Lamp2 Switched ON'

@app.route('/lamp2off')
def lamp2off():
    GPIO.output(20,False)
    return 'Lamp2 Switched OFF'

@app.route('/fan_on')
def fanon():
    GPIO.output(21,True)
    return 'Fan Switched ON'

@app.route('/fan_off')
def fanoff():
    GPIO.output(21,False)
    return 'Fan Switched OFF'

if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0')
