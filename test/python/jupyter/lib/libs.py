from IPython.core.interactiveshell import InteractiveShell
from apscheduler.schedulers.base import BaseScheduler
from apscheduler.schedulers.blocking import BlockingScheduler
from apscheduler.triggers.cron import CronTrigger
from apscheduler.util import asbool
from bs4 import BeautifulSoup
from datetime import datetime
from datetime import datetime, timedelta
from dateutil.relativedelta import relativedelta
from io import StringIO
from pytube import YouTube
from pytubefix import YouTube
from pytubefix.cli import on_progress
from threading import Thread, Event
import csv
import json
import matplotlib.dates as mdates
import matplotlib.pyplot as plt
import mplfinance as mpf
import numpy as np
import os
import sys
import pandas as pd
import pytube
import requests
import shutil
import talib
import threading
import time
import yfinance as yf
import yt_dlp
import os
import sys
import json
import argparse
import csv
from dotenv import load_dotenv
import traceback
from datetime import datetime
import time
from openai import OpenAI

