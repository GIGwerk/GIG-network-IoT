# SQLite Configuration
database_path = '/home/path_to_customer_feedback_log.db'

import serial
from sqlalchemy.ext.automap import automap_base
from sqlalchemy.orm import Session
from sqlalchemy import engine
from log_mapper import Log
import time

# You may set up the serial port here. For our example it was /dev/ttyACM0
arduino = serial.Serial('/dev/ttyACM0', 9800, timeout=.1)

sqlalchemy_map_base = automap_base()
sqlalchemy_engine = engine.create_engine('sqlite:///' + database_path)
sqlalchemy_map_base.prepare(sqlalchemy_engine, reflect=True)
sqlalchemy_session = Session(sqlalchemy_engine)

while True:
    data = arduino.readline()[:-2]  # the last bit gets rid of the new-line chars

    if data:
        log_entry = Log(rating=data, timestamp=time.time())
        sqlalchemy_session.add(log_entry)
        sqlalchemy_session.commit()
