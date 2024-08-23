pipeline {
    agent any
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
