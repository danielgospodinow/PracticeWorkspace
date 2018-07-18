var translation = {C:'G', G:'C', A:'U', T:'A'}

var toRNA = function(strand) {
	return strand.split('').map(function(nt) {
		return translation[nt]
	}).join('')
}

module.exports = toRNA