const { SerialPort } = require('serialport')
const { ReadlineParser } = require('@serialport/parser-readline')
const parser = new ReadlineParser()
const port = new SerialPort({
    path: '/dev/ttyUSB1',
    baudRate: 9600,
})

port.on("open",open)

function open(){
  console.log("Connected")
}

const parser2 = port.pipe(new ReadlineParser({delimiter: '\r\n'}))
parser2.on("data",getdata)

function getdata(data){
  console.log(data)
}