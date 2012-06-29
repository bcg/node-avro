var NAvro = require('../build/Release/navro').NAvro;

console.log(NAvro);

var avroRecord = new NAvro('schema.json');
console.log(avroRecord);
avroRecord.encode({test: 'tester'});
