from time import sleep
from functools import wraps
import logging
logging.basicConfig()
log=loggin.getLogger("retry")

def retry(f):
	@wraps(f)
	def wrapped_f(*args,**kwargs):
		MAx_ATTEMPTS=5
		try:
			return f()
