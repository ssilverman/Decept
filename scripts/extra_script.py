import time

Import("env")

# Add a delay before starting the tests, to accommodate the Teensy restarting
if "test" in env.GetBuildType():
    env.AddPostAction("upload", lambda *_, **__: time.sleep(4))
