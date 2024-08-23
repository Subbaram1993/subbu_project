pipeline {
    agent any

    tools {
        nodejs 'Node.js' {
            installDir 'C:\\Program Files\\Jenkins\\tools\\nodejs'
            version 'v20.17.0'
        }
    }

    stages {
        stage('Build') {
            steps {
                env.NODE_HOME = 'C:\\Program Files\\Jenkins\\tools\\nodejs'
                env.PATH = "${env.NODE_HOME}\\bin;${env.PATH}"
                sh 'npm run build'
            }
        }
    }
}
