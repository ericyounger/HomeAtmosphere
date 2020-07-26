import rumps
import requests

class Atmosphere(rumps.App):
    @rumps.timer(10)
    def prefs(self, _):
        try:
            result = requests.get('http://localhost:3000/atmosphere/recent').json()[0]

            temperature = result["temperature"]
            humidity = result["humidity"]
            print("loop")
            self.title = "T: {}°C, H : {}%".format(temperature, humidity)
        except: 
            self.title = "Not connected"


if __name__ == "__main__":
    Atmosphere("Loading..").run()
    