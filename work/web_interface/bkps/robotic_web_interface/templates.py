'''
TEMPLATE INITIALISATION & TOOLS
-------------------------------------------------------------------------------
'''
# 3rd Party Imports
import jinja2


def get(path):
    global env
    return env.get_template(path)
        

# Create the template environment.
#env = jinja2.Environment(loader=jinja2.FileSystemLoader('static/templates'))
env = jinja2.Environment(loader=jinja2.FileSystemLoader('static/examples'))

