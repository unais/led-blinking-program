'''
TEMPLATE INITIALISATION & TOOLS
-------------------------------------------------------------------------------
'''
# Python Standard Library Imports
pass

# 3rd Party Imports
import jinja2

# Custom Imports
pass

def get(path):
    global env
    return env.get_template(path)
        

# Create the template environment.
env = jinja2.Environment(loader=jinja2.FileSystemLoader('static/templates'))
