from flask import Flask
from flask import request, render_template_string

app = Flask(__name__)


def filtered(template):
    blacklist = ["{{", "}}", "_", "flag", "request", "cat", "tac", "+", "."]
    for b in blacklist:
        if b in template:
            return True
    return False


@app.route("/", methods=["GET"])
def index():
    name = request.args.get("name")
    if name:
        if filtered(name):
            return "Hacker? get out!"
        else:
            template = """
                <div class="center-content error">
                    <h1>Hello, %s</h1>
                </div> 
            """ % (
                name
            )
            return render_template_string(template)
    else:
        resp = """/?name=test
        <!-- /hint -->"""
        return resp


@app.route("/hint")
def getHint():
    return "https://tttang.com/archive/1698"


app.run("0.0.0.0", 8880)
