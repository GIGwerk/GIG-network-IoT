from sqlalchemy import Table, MetaData, Column, ForeignKey, Integer, String
from sqlalchemy.orm import mapper

metadata = MetaData()

log = Table('log', metadata,
            Column('log_id', Integer, primary_key=True),
            Column('rating', String(1)),
            Column('timestamp', Integer))


class Log(object):
    def __init__(self, rating, timestamp):
        self.rating = rating
        self.timestamp = timestamp

mapper(Log, log)
