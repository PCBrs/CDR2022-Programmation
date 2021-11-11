function SendButtonPompe()
{
    var xhttp = new XMLHttpRequest();
    var NumPump = document.getElementById('NumPump').options[document.getElementById('NumPump').selectedIndex].value;
    xhttp.open("GET", "NumPump", true);
    xhttp.send();
}

function SendButtonElectrovanne()
{

}
function SendButtonBras()
{

}

