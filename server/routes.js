
function getMostRecentAtmosphericData(req, res){
    console.log("GET request to get most recent data")
    async function getMostRecent(){
      const results = await Atmosphere.find().sort({"createdAt": -1}).limit(1)
      res.send(results);
      }
      getMostRecent();
  }

function getAllAtmosphericData(req,res){
    console.log("GET request to get all atmospheric data")
    async function getAllResults(){
        const results = await Atmosphere.find();
        res.send(results);
        }
        getAllResults();
      
}


function postAtmosphericData(req,res){
    console.log("POST request to post atmospheric data")
    let result = Atmosphere.create(req.body);
    res.status(201).send();
}





  module.exports = {
      getMostRecentAtmosphericData,
      postAtmosphericData,
      getAllAtmosphericData
  }