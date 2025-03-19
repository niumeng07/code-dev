import os
import sys
import json
import codecs

import time
from datetime import datetime

from pyspark.sql.functions import col, lit, length, row_number, when
from pyspark.sql import SparkSession
from pyspark import SparkConf, SparkContext, SQLContext
import pyspark.sql.functions as F
from pyspark.sql.types import *
from pyspark.sql.window import Window
from pyspark import SparkFiles

def get_spark(app_name='test'):
    os.environ["SPARK_HOME"] = "/Users/liuda/Library/CloudStorage/Dropbox/shareit/code/trading/spark-3.5.3-bin-hadoop3/"
    os.environ["PYSPARK_PYTHON"] = "/opt/homebrew/bin/python3.10"
    os.environ["JAVA_HOME"] = "/opt/homebrew/opt/openjdk@11/libexec/openjdk.jdk/Contents/Home"
    # os.environ["SPARK_LOCAL_IP"] = "192.168.11.215:3011"

    config = SparkConf()
    spark = SparkSession.builder \
        .appName(app_name) \
        .config(conf=config) \
        .enableHiveSupport() \
        .getOrCreate()
    return spark